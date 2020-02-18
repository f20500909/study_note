#include <deque>
#include <iostream>
#include <sstream>


void coCoo(std::stringstream& text) {

	int window=4;//window��С
	std::deque<std::string> ids;
	std::string center;
	std::string context;

	text >> context;

	ids.push_back(context);

	while (!text.eof()) {
		text >> center;
		//����ֻ��һ���ʣ�����
		if (center.empty()) {
			continue;
		}

		for (int i = 0; i != ids.size(); ++i) {
			std::cout <<  ids[i] <<" "<<center << std::endl;
		}

		//If line breaks, separate context between paragraphs
		//��һ�н���,���ids��flags,���¶�ȡһ���ʵ�ids����
		//peek�������ڶ�ȡ��������һ���ַ����������ƶ���ָ��
		if (text.peek() == '\n') {
			ids.clear();
			text >> context;
			ids.push_back(context);
			center = "";
		}
		else {
			//��������������ڵ����� window ���Ƴ���������
			if (ids.size() > window-1) {
				ids.pop_front();
			}
			//���û�е�����,Ҳû�дﵽ�������ڵ�����,��idѹ��ids��;
			ids.push_back(center);
		}
	}
	return;
}

int main() {

	std::stringstream text("�� �� һ�� �� ���� ���� ���� ���� ���� ��\nʵ�� ʹ�� ʱ ���� �� stringstream �滻 Ϊ ifstream");
	coCoo(text);

	std::cin.get();
	return 0;
}
