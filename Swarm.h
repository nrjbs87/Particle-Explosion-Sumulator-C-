/*
 * Swarm.h
 *
 *  Created on: Mar 31, 2020
 *      Author: Neeraj
 */

#ifndef SWARM_H_
#define SWARM_H_
#include  "Particle.h"

namespace nb {

class Swarm {

public:
	const static int NPARTICLES = 3000;
private:
	Particle *m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles(){return m_pParticles;};

};

} /* namespace nb */

#endif /* SWARM_H_ */
