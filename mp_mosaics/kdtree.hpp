/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
	if (first[curDim] == second[curDim])
		return first < second;
	return first[curDim] < second[curDim]; 
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
 
	// don't need to invoke sqrt; just compare squared distances
	int potDist = 0;
	int bestDist = 0;
	for (int i = 0; i < Dim; i++) {
		potDist += (target[i] - potential[i]) * (target[i] - potential[i]);
		bestDist += (target[i] - currentBest[i]) * (target[i] - currentBest[i]);
	}
	if (potDist == bestDist)
		return potential < currentBest;

     return potDist < bestDist;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
	if (newPoints.empty())
		return;

	// copy newPoints into a vector we can modify
	vector<Point<Dim>> points = newPoints;

	// finds the median node and sets it as the root node
	
	// then recursively makes the rest of the tree
	makeNodes(root, points, 1);

}

//template <int Dim>
//KDTreeNode KDTree<Dim>::makeNodes(vector<Point<Dim>> points) {
//	int median_pt = std::floor((points.size() - 1) / 2);
//	Point<Dim> median = findMedian(points, 0, points.size() - 1, median_pt, 0);
//	root = new KDTreeNode(median);
//	
//	root->left = makeNode(
//}

/** helper function for recursively constructing tree */
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::makeNodes(KDTreeNode *& subroot, vector<Point<Dim>> points, int dimension) {

	if (points.size() == 0) {return NULL;}
	if (points.size() == 1) { return new KDTreeNode(points[dimension-1]); }

	int median_pt = std::floor((points.size() - 1) / 2);
	Point<Dim> median = findMedian(points, 0, points.size() - 1, median_pt, 0);
	std::cout<<median[0]<<std::endl;
	subroot = new KDTreeNode(median);

	int newDim;	

	if (Dim == 1)
		newDim = 1;
	else
		newDim = (dimension + 1) % (Dim + 1);
	std::cout<<"newDim: "<<newDim<<std::endl;

	vector<Point<Dim>> left_v;
	for (Point<Dim> p : points) {
		if (p != median)
			left_v.push_back(p);
		else
			break;
	}
	subroot->left = makeNodes(subroot->left, left_v, newDim);

	vector<Point<Dim>> right_v;
	for (unsigned i = left_v.size() + 1; i < points.size(); i++) {
		right_v.push_back(points[i]);
	}
	
	subroot->right = makeNodes(subroot->right, right_v, newDim);
	return subroot;
}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>> points, int L, int R, int dim) {
	int x = points[R][dim-1];
	int i = L;
	for (int j = L; j < R; j++) {
		if (points[j][dim] <= x)
			std::swap(points[i], points[j]);
			i++;
	}
	std::swap(points[i], points[R]);
	return i;

}

template <int Dim>
Point<Dim> KDTree<Dim>::findMedian(vector<Point<Dim>> points, int L, int R, int med_pt, int dim) {
	int index = partition(points, L, R, dim);
	
	if (index - 1 == med_pt - 1)
		return points[index];

	if (index - 1 > med_pt - 1)
		//recurse for left subarray
		return findMedian(points, L, index - 1, med_pt, dim);

	// or recurse for right subarray
	return findMedian(points, index + 1, R, med_pt - index + L - 1, dim);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return Point<Dim>();
}

