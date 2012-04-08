#pragma once

#include <QAbstractTableModel>

#include "Physics/Environment.hpp"

class Environment;

class RobotTableModel: public QAbstractTableModel
{
	Q_OBJECT;

public:
	// Duplicate table to store robot info to avoid needing direct link to Environment
	struct RobotID {
		int visibility;
		bool ballSensorWorks;
		bool chargerWorks;
		unsigned int shell;
		Robot::RobotRevision revision;
	};

signals:
  void setRobotVisibility(int visibility);
  void setBallSensorWorks(bool works);
  void setChargerWorks(bool works);

public:

	typedef QMap<unsigned int, RobotID* > RobotIDMap;

	RobotTableModel(const Environment *env);

	// true = blue
	bool teamForRow(int row) const;

	// Access elements by row
	unsigned int shellForRow(int row) const;
	const RobotID * robotForRow(int row) const;
	RobotID * robotForRow(int row);

	virtual int columnCount(const QModelIndex &parent) const;
	virtual int rowCount(const QModelIndex &parent) const;

	virtual Qt::ItemFlags flags(const QModelIndex &index) const;

	virtual QVariant data(const QModelIndex &index, int role) const;

	virtual bool setData(const QModelIndex &index, const QVariant &value, int role);

	virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
	RobotIDMap _yellow, _blue;
};



