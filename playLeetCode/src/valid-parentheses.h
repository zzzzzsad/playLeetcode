/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�

ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:

    ����: "()"
    ���: true

ʾ�� 2:

    ����: "()[]{}"
    ���: true

ʾ�� 3:

    ����: "(]"
    ���: false

ʾ�� 4:

    ����: "([)]"
    ���: false

ʾ�� 5:

    ����: "{[]}"
    ���: true

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/valid-parentheses
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע������������Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#ifndef _PLAY_LEETCODE_VALID_PARENTHESES_H_
#define _PLAY_LEETCODE_VALID_PARENTHESES_H_

namespace valid_parentheses
{
    int test();
}

#endif // !_PLAY_LEETCODE_VALID_PARENTHESES_H_