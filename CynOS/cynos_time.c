/*
Copyright 2020 chenyanan

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "cynos_cfg.h"
#include "cynos_time.h"
#include "cynos_kernel.h"

time_hook_fun gtime_hook[TIME_HOOK_MAX];



char cynos_tim_base_login(void(*time_hook)(unsigned int time))
{
	static char cynos_tim_base_init = 0;
	
	unsigned char index=0;
	if(cynos_tim_base_init)
	{
		for(index=0;index<TIME_HOOK_MAX;index++)
		{
			if(gtime_hook[index]==0)
			{
				gtime_hook[index]=time_hook;
				return CYNOS_OK;
			}
		}
		
		return CYNOS_ERR_MEM;
	}
	else
	{
		cynos_tim_base_init=0X55;
		memset(gtime_hook,0,TIME_HOOK_MAX*sizeof(time_hook_fun));
		gtime_hook[0]=time_hook;
		return CYNOS_OK;
	}
	
}

char cynos_tim_base_logout(void(*time_hook)(unsigned int time))
{
	
	unsigned char index=0;
	
	for(index=0;index<TIME_HOOK_MAX;index++)
	{
		if(gtime_hook[index]==time_hook)
		{
			gtime_hook[index]=0;
			return CYNOS_OK;
		}
	}
	
	return CYNOS_ERR;	
}

/*该函数必须被调用（为内核及所有任务提供时间片段）*/
void cynos_time_run(unsigned int timebase)
{
	unsigned char index=0;
	
	if(gcynos_sta.init_sta==0x55)
	{
		for(index=0;index<TIME_HOOK_MAX;index++)
		{
			if(gtime_hook[index]!=0)
			{
				gtime_hook[index](timebase);
			}
		}
	}
}










