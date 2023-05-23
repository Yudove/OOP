#ifndef _ACCOUNT_EXCEPTION_H_
#define _ACCOUNT_EXCEPTION_H_

class MinusException {
private:
	int exval;

public:
	MinusException(int val) :exval(val) {}
	void ShowExceptionInfo() const {
		cout << "��(��)�ݾ� " << exval << "�� ��ȿ���� �ʽ��ϴ�.!" << endl;
	}
};

class InsuffException {
private:
	int balance;
	int reqval;
public:
	InsuffException(int val, int req) :balance(val), reqval(req) {}

	void ShowExceptionInfo() const {
		cout << "�ܾ׿��� " << reqval - balance << "��(��) �����մϴ�.!" << endl;
	}
};

#endif
