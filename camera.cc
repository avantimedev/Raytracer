/*
 * =====================================================================================
 *
 *       Filename:  camera.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2012 18:37:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Johan Astborg (ja), into@avantimedev.net
 *        Company:  avantimedev
 *
 * =====================================================================================
 */

#include "camera.h"

std::ostream& operator<<(std::ostream &out, const Camera &c) {
	return out << "Camera" << c.pos << " " << c.dir;
}
