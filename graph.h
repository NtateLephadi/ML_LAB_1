#include <vector>

#ifndef GRAPH_H
#define GRAPH_H

class graph{
private:
    std::vector<std::vector<int>> points;
    std::vector<std::vector<double>> cluster1, cluster2, cluster3;
    std::vector<double> centroid1, centroid2, centroid3;
    std::vector<double> distance1, distance2, distance3;

public:
  graph();

  ~graph();

  void set_points(std::vector<std::vector<int>>);

  void set_cluster1(
    std::vector<std::vector<double>>
  );

  void set_cluster2(
    std::vector<std::vector<double>>
  );

  void set_cluster3(
    std::vector<std::vector<double>>
  );

  void set_centroid1(
    std::vector<double>
  );

  void set_centroid2(
    std::vector<double>
  );

  void set_centroid3(
    std::vector<double>
  );

  void set_distance1(
    std::vector<double>
  );

  void set_distance2(
    std::vector<double>
  );

  void set_distance3(
    std::vector<double>
  );

  void to_string();

  double calculate_distance(std::vector<int>, std::vector<double>);

  void load_distances();

  int minimum_distance();
};

#endif
