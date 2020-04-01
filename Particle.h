/*
 * Particle.h
 *
 *  Created on: Mar 31, 2020
 *      Author: Neeraj
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace nb {

struct Particle {

	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;
private:
	void init();
public:
	void update(int interval);
	Particle();
	virtual ~Particle();
};

} /* namespace nb */

#endif /* PARTICLE_H_ */
