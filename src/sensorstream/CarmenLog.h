#ifndef CARMENLOG_H_
#define CARMENLOG_H_

#include <sensorstream/LogReader.h>
#include <sensorstream/LogWriter.h>
#include <sensors/AbstractReading.h>
#include <sensors/LaserReading.h>
#include <geometry/point.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/** \def MAX_LINE_SIZE The maximum length of a line. */
#define MAX_LINE_SIZE 8192

/** 
 * Representation of a CARMEN log reader. It implements the LogReader class for the CARMEN log file format.
 *
 * @author Gian Diego Tipaldi
 */

class CarmenLogReader: public LogReader{
    public:
	/** Virtual Default destructor. */
	virtual ~CarmenLogReader() { }
	/** Read a log from an inputstream. */
	virtual void readLog(std::istream& _stream, std::vector<AbstractReading*>& _log) const;
    protected:
	/** Read a single line from the stream. */
	AbstractReading* readLine(std::istream& _stream) const;
	/** Parse the old laser structure (FLASER). */
	LaserReading* parseFLaser(std::istream& _stream) const;
	/** Parse the new laser structure (ROBOTLASERX). */
	LaserReading* parseRobotLaser(std::istream& _stream) const;
	/** Parse the raw laser structure (RAWLASERX). */
	LaserReading* parseRawLaser(std::istream& _stream) const;
};

/** 
 * Representation of a CARMEN log writer. It implements the LogWriter class for the CARMEN log file format.
 *
 * @author Gian Diego Tipaldi
 */

class CarmenLogWriter: public LogWriter{
    public:
	/** Virtual Default destructor */
	virtual ~CarmenLogWriter() { }
	/** Write a log to an outputstream */
	virtual void writeLog(std::ostream& _stream, const std::vector<AbstractReading*>& _log) const;
    protected:
	/** Write a single line to the stream. */
	void writeLine(std::ostream& _stream, const AbstractReading* _reading) const;
	/** Write the old laser structure (FLASER). */
	void writeFLaser(std::ostream& _stream, const LaserReading* _reading) const;
	/** Write the new laser structure (ROBOTLASERX). */
	void writeRobotLaser(std::ostream& _stream, const LaserReading* _reading) const;
	/** Write the raw laser structure (RAWLASERX). */
	void writeRawLaser(std::ostream& _stream, const LaserReading* _reading) const;
};

#endif
