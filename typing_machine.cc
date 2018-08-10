// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	m_home = m_end = m_cur = new Node('\0');;
}

void TypingMachine::HomeKey() {
	m_cur = m_home;
}

void TypingMachine::EndKey() {
	m_cur = m_end;
}

void TypingMachine::LeftKey() {
	if (m_cur->GetPreviousNode())
		m_cur = m_cur->GetPreviousNode();
}

void TypingMachine::RightKey() {
	if (m_cur->GetNextNode())
		m_cur = m_cur->GetNextNode();
}

bool TypingMachine::TypeKey(char key) {
	Node *p;

	if (key < 0x20 || key > 0x7E)
		return false;

	if (!m_cur)
		return false; // ASSERT

	p = m_cur->InsertPreviousNode(key);

	if (m_home == m_cur)
		m_home = p;

	return true;
}

bool TypingMachine::EraseKey() {
	if (!m_cur)
		return false; // ASSERT

	return m_cur->ErasePreviousNode();
}

std::string TypingMachine::Print(char separator) {
	//std::string str;
	char str[101];
	Node *p = m_home;
	int i = 0;

	while (p) {
		if (p == m_cur && separator != 0)
			str[i++] = separator;
		str[i++] = p->GetData();
		p = p->GetNextNode();
	}

	return std::string(str);
}
