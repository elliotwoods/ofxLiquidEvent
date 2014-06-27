#pragma once

//#if __cplusplus<201103L
//	#define OFXLIQUIDEVENT_USE_TR1
//#endif

#ifdef OFXLIQUIDEVENT_USE_TR1
	#include <tr1/functional>
	#define FUNCTION tr1::function
#else
	#include <functional>
	#define FUNCTION std::function
#endif

#include <map>


template<class ArgType>
class ofxLiquidEvent {
	/*
	class HandleLegacyEvent {
	public:
		HandleLegacyEvent(ofEvent<ArgType> & event) : event(event) {
			ofAddListener(event, this, & callback);
		}

		~HandleLegacyEvent() {
			ofRemoveListener(this->event, this, & callback);
		}

		ofxLiquidEvent<ArgType> liquidEvent;
	protected:
		void callback(ArgType & args) {
			this->liquidEvent(args);
		}
		ofEvent<ArgType> & event;
	};
	*/

	typedef FUNCTION<void (ArgType&)> Functor;
	typedef int32_t IndexType; // use negative index for bottom of stack
	struct Index {
		Index(IndexType order, void* owner) {
			this->order = order;
			this->owner = owner;
		}
		bool operator<(const Index& other) const {
			return this->order < other.order;
		}
		bool operator==(const IndexType& otherIndex) const {
			return this->order == otherIndex;
		}
		IndexType order;
		void* owner;
	};
	typedef std::map<Index, Functor> FunctorMap;
	typedef std::pair<Index, Functor> Pair;
public:
	void operator+=(Functor functor) {
		this->addListener(functor, 0);
	}
	void addListener(Functor functor, void* owner) {
		IndexType order = 0;
		if (!this->listeners.empty()) {
			//loop until we find a free index
			while (listeners.find(Index(order, 0)) != listeners.end()) {
				order++;
			}
		}
		this->listeners.insert(Pair(Index(order, owner), functor));
	}
	void addListener(Functor functor, IndexType order, void* owner) {
		//loop until we find a free index
		while (listeners.find(Index(order, 0)) != listeners.end()) {
			order++;
		}
		this->listeners.insert(Pair(Index(order, owner), functor));
	}
	void removeListeners(void* owner) {
		vector<IndexType> toRemove;
		for(auto iterator : this->listeners) {
			if (iterator.first.owner == owner) {
				toRemove.push_back(iterator.first.order);
			}
		}
		for(auto order : toRemove) {
			this->listeners.erase(Index(order, owner));
		}
	}
	void notifyListeners(ArgType& arguments) {
		for(auto listener : this->listeners) {
			listener.second(arguments);
		}
	}
	void operator()(ArgType& arguments) {
		this->notifyListeners(arguments);
	}
protected:
	FunctorMap listeners;
};