#pragma once

#define SINGLE(type) static type* GetInst()\
					 {\
						 static type mgr; return &mgr; \
					 }