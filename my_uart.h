/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-05-31     Administrator       the first version
 */
#ifndef MY_UART_H_
#define MY_UART_H_

#define SAMPLE_UART_NAME       "uart2"       /* ��Ҫ�������豸 */
static rt_device_t serial;                   /* �豸��� */
static char str[] = "hello RT-Thread!\r\n";  /* ��Ҫ���͵����� */

static int uart_sample(void)
{
    rt_err_t ret = RT_EOK;
    rt_size_t send_len = 0;

    /* ����ϵͳ�еĴ����豸 */
    serial = rt_device_find(SAMPLE_UART_NAME);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return -RT_ERROR;
    }

    /* ���жϽ��ռ���ѯ����ģʽ�򿪴����豸 */
    ret = rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
    if (ret != RT_EOK)
    {
        rt_kprintf("open device failed\r\n");
        return -RT_ERROR;
    }
    /* �����ַ��� */
    send_len = rt_device_write(serial, 0, str, (sizeof(str) - 1));
    if (send_len != sizeof(str) - 1)
    {
        rt_kprintf("send data failed\r\n");
        return -RT_ERROR;
    }
    /* �ر��豸 */
    ret = rt_device_close(serial);
    if (ret != RT_EOK)
    {
        rt_kprintf("close device failed\r\n");
        return -RT_ERROR;
    }

    rt_kprintf("serial device test successful\r\n");

    return RT_EOK;
}




#endif /* MY_UART_H_ */
