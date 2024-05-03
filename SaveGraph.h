#ifndef Save_H
#define Save_H

#include "Actions\Action.h"

class SaveGraph : public Action
{
private:
	string filename;
public:
	SaveGraph(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif

