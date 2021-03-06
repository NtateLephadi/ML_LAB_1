#include "graph.h"
#include <iostream>


int main(int argc, char const *argv[]) {
  /* code */
  graph g;
  g.set_points(
    {
      {2, 10},
      {2, 5},
      {8, 4},
      {5, 8},
      {7, 5},
      {6, 4},
      {1, 2},
      {4, 9}
    }
  );

  g.set_cluster1(
    {
      {2, 10},
      {2, 5},
      {8, 4}
    }
  );

  g.set_cluster2(
    {
      {5, 8},
      {7, 5},
      {6, 4}
    }
  );

  g.set_cluster3(
    {
      {1, 2},
      {4, 9}
    }
  );

  g.set_distance1(
    {
      0, 0, 0, 0, 0, 0, 0, 0
    }
  );

  g.set_distance2(
    {
      0, 0, 0, 0, 0, 0, 0, 0
    }
  );

  g.set_distance3(
    {
      0, 0, 0, 0, 0, 0, 0, 0
    }
  );

  g.set_centroid1(
    {
      3.0, 9.5
    }
  );

  g.set_centroid2(
    {
      6.5, 5.25
    }
  );

  g.set_centroid3(
    {
      1.5, 3.5
    }
  );

  for (size_t i = 1; i < 5; i++) {
    /* code */
    std::cout << "iteration" << ' ' << i;
    std::cout << '\n';

    g.load_distances();

    // g.to_string();

    g.cluster_points(g.minimum_distance());

    g.new_centroid();
  }
  return 0;
}
