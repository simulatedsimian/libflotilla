#include "moduletouch.h"

void ModuleTouch::Init(int chan) {
	SetChannel(chan);
	m_prevState = 255;  // initially set to impossible state so we get at least 1 update at start
}

void ModuleTouch::Update(SerialStream* stream) {
	uint8_t newState = GetState();

	if (newState != m_prevState) {
		m_prevState = newState;
		printUpdateHeader(stream);
		printList(stream, m_prevState & 1, (m_prevState & 2) >> 1, (m_prevState & 4) >> 2,
		          (m_prevState & 8) >> 3);
	}
}
