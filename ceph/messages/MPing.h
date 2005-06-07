
#ifndef __MPING_H
#define __MPING_H

#include "msg/Message.h"


class MPing : public Message {
 public:
  int seq;
  MPing(int s) : Message(MSG_PING) {
	seq = s;
  }
  MPing() : Message(MSG_PING) {}

  virtual void decode_payload(crope& s, int& off) {
	s.copy(0, sizeof(seq), (char*)&seq);
	off += sizeof(seq);
  }
  virtual void encode_payload(crope& s) {
	s.append((char*)&seq, sizeof(seq));
  }

  virtual char *get_type_name() { return "ping"; }
};

#endif
