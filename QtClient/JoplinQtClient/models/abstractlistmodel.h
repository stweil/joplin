#ifndef ABSTRACTLISTMODEL_H
#define ABSTRACTLISTMODEL_H

#include <stable.h>
#include "models/basemodel.h"

namespace jop {

class AbstractListModel : public QAbstractListModel {

	Q_OBJECT

public:

	enum ModelRoles {
		IdRole = Qt::UserRole + 1,
		TitleRole,
		RawRole
	};

	AbstractListModel();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	//QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
//	BaseModel atIndex(int index) const;
//	BaseModel atIndex(const QModelIndex &index) const;

protected:

	virtual BaseModel newBaseModel() const;
	virtual int baseModelCount() const;

	virtual BaseModel cacheGet(int index) const;
	virtual void cacheSet(int index, const BaseModel& baseModel);
	virtual bool cacheIsset(int index) const;
	virtual void cacheClear();

private:

	bool virtualItemShown_;

public slots:

	void showVirtualItem();
	bool virtualItemShown() const;
	void hideVirtualItem();
	QHash<int, QByteArray> roleNames() const;

};

}

#endif // ABSTRACTLISTMODEL_H