/*
 ============================================================================
 Name        : CTransactionManager.h
 Author      : Rafael Gu
 Version     : 1.0
 Copyright   : GPL
 Description :
 ============================================================================
 */

#ifndef _C_TRANSACTION_MANAGER_H_
#define _C_TRANSACTION_MANAGER_H_

#include "../common/CTimerManager.h"
#include "../common/CMutex.h"

class CTransaction;

#include <map>

typedef std::map<const c1_ *, CTransaction *> TransactionMap;

class CTransactionManager: public CTimerManager {
public:
	static CTransactionManager *instance();

	none_ work();

	CTransaction *findTransaction(const c1_ *sessionId);
	bool_ registerTransaction(CTransaction *transaction);
	bool_ unregisterTransaction(CTransaction *transaction);

protected:
	bool_ __onTimer(ub8_ timerId, obj_ parameterI, obj_ parameterII);

private:
	CTransactionManager();
	virtual ~CTransactionManager();

	static CTransactionManager *_tm;

	TransactionMap _transactionMap;
	CMutex _mutex;
};

#endif // _C_TRANSACTION_MANAGER_H_
