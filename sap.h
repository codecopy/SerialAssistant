/*
 * Serial Assistant Parser
 * �๦�ܴ��ڵ������ֽ�������
 *
 */

#ifndef SAP_H
#define SAP_H

#ifdef __cplusplus
extern "C" {
#endif

/* ������� */
#define MAX_CAMMAND_FUNC_SIZE   9
#define MAX_SWITCH_FUNC_SIZE    4
#define MAX_RECV_BUF            20
#define MAX_SEND_BUF            20
#define MAX_CAMMAND_SIZE        9
#define MAX_SWITCH_SIZE         4
#define MAX_PID_SIZE            6
#define MAX_CUSTOM_ARG_SIZE     10
#define MAX_ARG_WATCH_SIZE      10

#define START_BYTE              0xfe
#define END_BYTE                0xee

enum { Cammand, Switch, PID_Get, CustomGet, PID_Set, CustomSet, ArgWatch};


/* ���º������û�ʵ�֣�
 * Ҫʹ�����������������û����붨�����º�����
 *
 * sap_send_byte��
 *     ���ݷ��ͣ�����һ���ֽڵ���λ��
 *
 * sap_cammand_handler��
 *     ���յ�һ��������û�Ҫ������
 *     cammand_index�� �յ���������
 *     ���յ�һ������󣬴˺����ᱻ�����������
 *     �û���ͨ��cammand_index��ֵ�жϵ��׽��յ����ĸ�����
 *
 * sap_switch_handler��
 *     ���յ�һ������������û�Ҫ������
 *     switch_index�����ر��
 *     switch_state������״̬(0���رգ�1����)
 *     ���յ�һ����������󣬴˺����ᱻ�����������
 *     �û���ͨ��switch_index��ֵ�жϵ��׽��յ����ĸ���������
 *     �û���ͨ��switch_state��ֵ�ж�������ص�״̬
 */
void sap_send_byte(unsigned char byte);
void sap_cammand_handler(int cammand_index);
void sap_switch_handler(int switch_index, int switch_state);


/* �û�ͨ���������º�����������λ����ʹ�ó���������λ������ͨ�ţ�
 *
 * sap_get_one_byte��
 *  �ڽ�����Ϣ����������ý���Դ�����ڴ��ڽ����ж���
 *
 * sap_bind_pid:
 *    ��pid������index��ʾPID��ţ�ʣ�µĲ����ǳ������pid�����ĵ�ַ
 *    �˺��������˳������pid��������λ����pidֵ
 *
 * sap_bind_custom_arg:
 *    ���Զ��������index��ʾ������ţ�arg_addr�ǳ��������ز����ĵ�ַ
 *
 * sap_bind_arg_watch��
 *    �󶨲������ӣ�index��ʾ������ţ�arg_addr�ǳ��������ز����ĵ�ַ
 * sap_send_arg_watch��
 *    ���󶨵Ĳ���������λ������������б�Ҫ����λ���������������ʱ�������
 *    index��������ţ��ò��������֮ǰӦ�úͳ������ĳ�������󶨣�ʹ��sap_bind_arg_watch��
 *
 * sap_send_all_arg_watchs��
 *    �����а󶨵Ĳ���������λ������������б�Ҫ����λ���������в�����ʱ�������
 *    �����ݽ϶�ʱ���˺���ִ�п��ܻ����
 */
void sap_get_one_byte(unsigned char byte);
void sap_bind_pid(int index, float *kp_addr, float *ki_addr, float *kd_addr);
void sap_bind_custom_arg(int index, float *arg_addr);
void sap_bind_arg_watch(int index, float *arg_addr);
void sap_send_arg_watch(int index);
void sap_send_all_arg_watchs(void);


/* ���º������ṩ����λ������ʹ�õĺ������û�������Ҫʹ����Щ����
 *
 */
#ifdef IN_UPCOMP
void sap_send_cammad(int cammadindex);
void sap_send_switch(int switch_index, int switch_state);
void sap_send_arg(int cmd_type, int index);
void sap_send_request(int request_type, int index);
void sap_get_send_data_frame(unsigned char *frame, int len);
void sap_get_recv_data_frame(unsigned char *frame, int len);
void sap_send_pid(int index);
#endif

#ifdef __cplusplus
}
#endif

#endif /* SERIAL_ASSISTANT_PARSE_H */
