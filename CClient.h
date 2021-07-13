#pragma once
#include <afxsock.h>

#define MAX_BUFFER_SIZE 2048
class CClient :
    public CSocket
{
public:
    virtual void OnClose(int nErrorCode);
    virtual void OnReceive(int nErrorCode);
};

