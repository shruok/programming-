#ifndef Load_H
#define Load_H

#include "Actions/Action.h"

class LoadGraph : public Action
{
private:
	string filename;  //the file name to be entered
public:
	LoadGraph(ApplicationManager* pApp);

	virtual void ReadActionParameters();


	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif
