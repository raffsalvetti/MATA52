/////////////////////////////////////////////////////////////////////////////
// Name:	democollection.cpp
// Purpose: Demo collection class implementation
// Author:	Moskvichev Andrey V.
// Created:	2008/11/12
// Copyright:	(c) 2008-2009 Moskvichev Andrey V.
// Licence:	wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include "democollection.h"

// demos
extern ChartDemo *insertionSortChart[];
extern int insertionSortChartCount;

extern ChartDemo *quickSortChart[];
extern int quickSortChartCount;

extern ChartDemo *bubbleSortChart[];
extern int bubbleSortChartCount;

extern ChartDemo *selectionSortChart[];
extern int selectionSortChartCount;

extern ChartDemo *mergeSortChart[];
extern int mergeSortChartCount;

static DemoCollection instance;

/**
 * Demo category.
 */
class Category
{
public:
	Category(wxString name, ChartDemo **charts, int chartCount)
	{
		m_name = name;
		m_chartDemos = charts;
		m_chartCount = chartCount;
	}

	const wxString &GetName()
	{
		return m_name;
	}

	const wxString &GetChartName(int chartIndex)
	{
		return m_chartDemos[chartIndex]->GetName();
	}

	ChartDemo *GetChartDemo(int chartIndex)
	{
		return m_chartDemos[chartIndex];
	}

	int GetChartCount()
	{
		return m_chartCount;
	}

private:
	wxString m_name;
	ChartDemo **m_chartDemos;
	int m_chartCount;
};

// demo categories
static Category *cats[] = {
		new Category(wxT("Insertion Sort"), insertionSortChart, insertionSortChartCount),
		new Category(wxT("Quick Sort"), quickSortChart, quickSortChartCount),
		new Category(wxT("Bubble Sort"), bubbleSortChart, bubbleSortChartCount),
		new Category(wxT("Selection Sort"), selectionSortChart, selectionSortChartCount),
		new Category(wxT("Merge Sort"), mergeSortChart, mergeSortChartCount),
};

//
// DemoCollection
//
DemoCollection::DemoCollection()
{
}

DemoCollection::~DemoCollection()
{
}

int DemoCollection::GetCategoryCount()
{
	return WXSIZEOF(cats);
}

const wxString &DemoCollection::GetCategory(int index)
{
	return cats[index]->GetName();
}

int DemoCollection::GetCategoryDemoCount(int index)
{
	return cats[index]->GetChartCount();
}

ChartDemo *DemoCollection::GetCategoryDemo(int catIndex, int demoIndex)
{
	return cats[catIndex]->GetChartDemo(demoIndex);
}

DemoCollection *DemoCollection::Get()
{
	return &instance;
}

