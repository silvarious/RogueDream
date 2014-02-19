#ifndef TIMER_H_
#define TIMER_H_

#include <set>
#include <boost/noncopyable.hpp>

struct Timer : private boost::noncopyable
{
	Timer(float expiration_time, bool start_active = false) :
		  current_time_(start_active ? 0 : expiration_time), expiration_time_(expiration_time)
		  { timers_.insert(this); }

	~Timer() { timers_.erase(this); }

	void reset() { current_time_ = 0; }
	bool active() const { return current_time_ < expiration_time_; }
	bool expired() const { return !active(); }

	float current_time() const { return current_time_; }

	static void updateAll(float elapsed_time);

private:
	void update(float elapsed_time)
	{ if (active()) current_time_ += elapsed_time; }

	float current_time_;
	const float expiration_time_;

	static std::set<Timer*> timers_;
};

#endif