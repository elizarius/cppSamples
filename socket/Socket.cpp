#include "Socket.h"
#include "SocketReader.h"
#include "SocketWriter.h"

using namespace cpp_samples;

Socket::Socket(SocketType type) : fd_(0), type_(type)
{
	socketWriterPtr_ = new SocketWriter(this);
	socketReaderPtr_ = new SocketReader(this);
}

Socket::~Socket()
{
	delete socketReaderPtr_;
	delete socketWriterPtr_;
}

void
Socket::send(Msg* pMsg)
	throw (CppSamplesException)
{
	if (!pMsg)
		throw CppSamplesException("invalid message");

	_send(pMsg);
}


void
Socket::sendReply(unsigned int _reqID, Msg* pMsg)
	throw (CppSamplesException)
{
/*
	if (!pMsg)
		throw CppSamplesException("invalid message");

	if (!_reqID)
		throw CppSamplesException("invalid request id");

	pMsg->id_ = _reqID;
	pMsg->type_ = MT_REPLY;
	_send(pMsg);
*/
}

void
Socket::_send(Msg* pMsg)
	throw (CppSamplesException)
{
// AELZ_31 wtire here send message part */
/*
	TransportData transportData(pMsg);
	int rc = socketWriterPtr_->writeData(&transportData);
	if (rc != SocketWriter::COMPLETED)
	{
		throw EX_MESSAGINGEXCEPTION_ERR("send failed", errno);
	}
*/
}

void
Socket::_receiveReply(Msg* pMsg)
	throw (CppSamplesException)
{
/*
    bool found = false;
    RequestMonitorHandle handle = EMPTY_REQUESTMONITORHANDLE;
    hashIterType iter;
    {
        Guard<FastLock> gaurd(reqLock_);
        iter = requestsStore_.find(pMsg->getID());
        if (iter != requestsStore_.end())
        {
            found = true;
            handle = iter->second;
            requestsStore_.erase(iter);
        }
    }

    if (found)
    {
        pthread_mutex_lock(&handle->lock_);
        if (handle->state_ == RS_RUNNING)
        {
            handle->state_ = RS_DONE;
            handle->replyMsgPtr_ = pMsg;
        }
        else
        {
            delete pMsg;
        }
        pthread_cond_signal(&handle->cond_);
        pthread_mutex_unlock(&handle->lock_);
    }
    else
    {
        TRACER(TRC_WARNING) << "No request handle found for received reply message {number, size, data, id} {"
                            << pMsg->getNumber()
                            << ", "
                            << pMsg->getLength()
                            << ", "
                            << (void*)pMsg->getData()
                            << ", "
                            << pMsg->getID()
                            << "}"
                            << std::endl;
        delete pMsg;
    }
*/
}


void
Socket::_messageReceived(Msg* pMsg)
	throw (CppSamplesException)
{
/*
	if (pMsg->getID() && pMsg->type_ == MT_REPLY)
	{
        _receiveReply(pMsg);
	}
	else if (pMsg->getID() && pMsg->type_ == MT_REQUEST)
	{
		requestReceived(pMsg);
	}
	else // normal message
	{
		messageReceived(pMsg);
	}
*/
}

void
Socket::_connectionClosed()
	throw (CppSamplesException)
{
/*
    socketWriterPtr_->close();
	// invalidate all bending requests
	hashIterType iter;
	RequestMonitorHandle handle = EMPTY_REQUESTMONITORHANDLE;
	Guard<FastLock>	gaurd(reqLock_);
	for (iter = requestsStore_.begin(); iter != requestsStore_.end(); iter++)
	{
		handle = iter->second;
		pthread_mutex_lock(&handle->lock_);	pMsg->id_ = 0;

		handle->state_ = RS_INVALID;
		handle->replyMsgPtr_ = 0;
		pthread_cond_signal(&handle->cond_);
		pthread_mutex_unlock(&handle->lock_);
	}

	// infrom application
	connectionClosed();
*/
}



