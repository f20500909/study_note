#include <iostream>
#include <functional>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>


typedef boost::geometry::model::point<float, 2, boost::geometry::cs::cartesian> point;
typedef std::pair<point, unsigned> item;


class Spatial {
public:
    Spatial() {
        setDistanceThreshold(5);
    }

    void insert(item&  item) {
        rtree.insert(item);
    }

    //插入点 其标识码为点的序列
    void insertPoint(point& p) {
        insertPoint(p,count++);
    }

    void insertPoint(point& p,int id) {
        item item = std::make_pair(p, id);
        insert(item);
    }

    void setDistanceThreshold(int dis) {
        distanceThreshold = dis;
    }

    std::vector<item> getVaildPoint() {
        std::vector<item> res;
        point sought = point(0, 0);

        auto _rule = [&](item const &v) {
            return boost::geometry::distance(v.first, sought) < distanceThreshold;
        };

        rtree.query(boost::geometry::index::satisfies(_rule), std::back_inserter(res));
        return res;
    }

    boost::geometry::index::rtree<item, boost::geometry::index::quadratic<16> > rtree;

    void test() {
        item temp = std::make_pair(point(2, 2), 2);
        insert(temp);
//        insert(std::make_pair(point(2, 2), 2));
//        rtree.insert(std::make_pair(point(7, 3), 3));
//        rtree.insert(std::make_pair(point(5, 2), 4));
//        rtree.insert(std::make_pair(point(6, 2), 5));
//        rtree.insert(std::make_pair(point(1, 6), 6));
//        rtree.insert(std::make_pair(point(1, 6), 7));
    }

    inline int getCount(){
        return count;
    }

    int distanceThreshold;
    int count;
};

int main(int argc, char *argv[]) {

    Spatial s;
    s.test();

    return 0;
}