/*
 ============================================================================
 Name        : Message.h
 Author      : Rafael Gu
 Version     : 1.0
 Copyright   : GPL
 Description :
 ============================================================================
 */

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "../config/Size.h"

namespace Message {

const ub4_ MSG_MAX_LENGTH = 512;

////////////////////////////////////
// type values in THeader
////////////////////////////////////
const ub2_ MT_CONTROL = 0x0001;
const ub2_ MT_ACCOUNT = 0x0002;
const ub2_ MT_SERVICE = 0x0003;

const ub2_ MT_SIGN_ACK = 0x0010;
const ub2_ MT_SIGN_LOG = 0x0020;
const ub2_ MT_SIGN_FEE = 0x0040;

////////////////////////////////////
// cmd values in THeader
////////////////////////////////////
// network messages: 0xXXXX except 0x8XXX
const ub2_ MC_HAND_SHAKE = 0x0001;
const ub2_ MC_HEART_BEAT = 0x0002;

// internal messages: 0x8XXX
const ub2_ MC_ON_TIMER = 0x8001;
const ub2_ MC_ON_OVER = 0x8002;

////////////////////////////////////
// lang values in THeader
////////////////////////////////////
const ub1_ ML_CN = 0x01;
const ub1_ ML_TW = 0x02;
const ub1_ ML_EN = 0x03;

////////////////////////////////////
// PDUs
////////////////////////////////////
#pragma pack(1)

struct THeader {
	ub2_ size;
	ub2_ type;
	ub2_ cmd;
	ub2_ ver;
	ub1_ lang;
	ub4_ seq;
	ub8_ stmp;
	ub8_ ext;
};

typedef THeader TMsg;

struct TAck {
	ub2_ code;
};

struct TPDUHandShake {
	THeader header;
	ub4_ build;
	c1_ sessionId[Size::SESSION_ID];
};

struct TPDUHandShakeAck {
	THeader header;
	TAck ack;
};

struct TPDUHeartBeat {
	THeader header;
};

struct TPDUHeartBeatAck {
	THeader header;
	TAck ack;
};

struct TPDUOnTimer {
	THeader header;
	ub8_ timerId;
	ub8_ parameter;
};

struct TPUDOnOver {
	THeader header;
	b4_ reason;
};

#pragma pack()
}

#endif // _MESSAGE_H_
