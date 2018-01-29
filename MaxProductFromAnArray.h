#pragma once

#include "Header.h"

// Function to find maximum product pair in an array of n elements
int  maxProduct(int arr[], int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return arr[0];
	}

	pair<int, int> Max, Min;
	Max.first = Max.second = INT_MIN;
	Min.first = Min.second = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (Max.first < arr[i])
		{
			Max.second = Max.first;
			Max.first = arr[i];
		}
		else if (Max.second > arr[i])
			Max.second = arr[i];

		if (Min.first > arr[i])
		{
			Min.second = Min.first;
			Min.first = arr[i];
		}
		else if (Min.second > arr[i])
			Min.second = arr[i];
	}

	if (Min.first*Min.second > Max.first*Max.second)
		return Min.first*Min.second;
	else
		return Max.first*Max.second;
}