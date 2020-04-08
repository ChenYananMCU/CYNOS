#ifndef __CYNOS_TASK_H
#define __CYNOS_TASK_H 

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif
#include "cynos_base.h"

typedef enum
{
	CynOSTask_FLOW_IDLE=0X10,
	CynOSTask_FLOW_STEP_1,
	CynOSTask_FLOW_STEP_2,
	CynOSTask_FLOW_STEP_3,
	CynOSTask_FLOW_STEP_4,
	CynOSTask_FLOW_STEP_5,
	CynOSTask_FLOW_STEP_6,
	CynOSTask_FLOW_STEP_7,
	CynOSTask_FLOW_STEP_8,
	CynOSTask_FLOW_STEP_9,
	CynOSTask_FLOW_STEP_A,
	CynOSTask_FLOW_STEP_B,
	CynOSTask_FLOW_STEP_C,
	CynOSTask_FLOW_STEP_D,
	CynOSTask_FLOW_STEP_E,
	CynOSTask_FLOW_STEP_F,
	CynOSTask_FLOW_DELAY,
}CynOSTask_FLOW;


typedef struct
{
	unsigned int  _time_cnt;
	unsigned int  _wait_time;
	unsigned char _init_flag;
	unsigned char _task_flow;
	unsigned char _task_next_flow;
}CynOSTask_Sta;

/*
	��������״̬�����ӿ�
*/

//״̬��ʼ����״̬����ʼΪIDLE״̬����������ã�
extern void Cynos_Task_Init(CynOSTask_Sta * cynostask_sta);
//״̬��ת����
extern void Cynos_TASK_Jump(CynOSTask_Sta * cynostask_sta,CynOSTask_FLOW next_step,unsigned int wait_time);
//��ʱ�Զ���ת��������ʱ��������ת������ã�
extern void Cynos_TASK_Delay(CynOSTask_Sta * cynostask_sta);
//����ʱ��
extern void Cynos_TASK_SystickHandle(CynOSTask_Sta * cynostask_sta,unsigned int time);
//��ȡ��ǰ״̬��״̬
extern unsigned char Cynos_GetTask_Step(CynOSTask_Sta * cynostask_sta);


//�û������ʼ���������û�������ڣ�
extern void Cynos_UserTask_Init(void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
