#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>

typedef boost::geometry::model::point<float, 2, boost::geometry::cs::cartesian> point;
typedef std::pair<point, unsigned> value;

int main(int argc, char *argv[]) {
    boost::geometry::index::rtree<value, boost::geometry::index::quadratic<16> > rtree;

    // create some values
    for (unsigned i = 0; i < 10; ++i) {
        point p = point(i, i);
        rtree.insert(std::make_pair(p, i));
    }

    // search for nearest neighbours
    std::vector<value> returned_values;
    point sought = point(5, 5);
    rtree.query(boost::geometry::index::satisfies([&](value const &v) { return boost::geometry::distance(v.first, sought) < 2; }), std::back_inserter(returned_values));

    // print returned values
    value to_print_out;
    for (size_t i = 0; i < returned_values.size(); i++) {
        to_print_out = returned_values[i];
        float x = to_print_out.first.get<0>();
        float y = to_print_out.first.get<1>();
        std::cout << "Select point: " << to_print_out.second << std::endl;
        std::cout << "x: " << x << ",y: " << y << std::endl;
    }

    return 0;
}