#include "math.h"
#include "graph.h"
#include <iostream>
#include <algorithm>
#include <limits>       // std::numeric_limits


graph::graph(){}

graph::~graph(){}

void graph::set_points(std::vector<std::vector<int>> points){
  this->points=points;
}

void graph::set_cluster1(
  std::vector<std::vector<double>> cluster1
){
  this->cluster1=cluster1;
}

void graph::set_cluster2(
  std::vector<std::vector<double>> cluster2
){
  this->cluster2=cluster2;
}

void graph::set_cluster3(
  std::vector<std::vector<double>> cluster3
){
  this->cluster3=cluster3;
}

void graph::set_centroid1(
  std::vector<double> centroid1
){
  this->centroid1=centroid1;
}

void graph::set_centroid2(
  std::vector<double> centroid2
){
  this->centroid2=centroid2;
}

void graph::set_centroid3(
  std::vector<double> centroid3
){
  this->centroid3=centroid3;
}

void graph::set_distance1(
  std::vector<double> distance1
){
  this->distance1=distance1;
}

void graph::set_distance2(
  std::vector<double> distance2
){
  this->distance2=distance2;
}

void graph::set_distance3(
  std::vector<double> distance3
){
  this->distance3=distance3;
}

void graph::to_string(){
    std::cout << "data" << '\n';
    for (size_t i = 0; i < this->points.size(); i++) {
      /* code */
      for (size_t j = 0; j < this->points[i].size(); j++) {
        /* code */
        std::cout << this->points[i][j] << ' ';
      }
      std::cout << '\n';
    }

    std::cout << "cluster1" << '\n';
    for (size_t i = 0; i < this->cluster1.size(); i++) {
      /* code */
      for (size_t j = 0; j < this->cluster1[i].size(); j++) {
        /* code */
        std::cout << this->cluster1[i][j] << ' ';
      }
      std::cout << '\n';
    }

    std::cout << "cluster2" << '\n';
    for (size_t i = 0; i < this->cluster2.size(); i++) {
      /* code */
      for (size_t j = 0; j < this->cluster2[i].size(); j++) {
        /* code */
        std::cout << this->cluster2[i][j] << ' ';
      }
      std::cout << '\n';
    }

    std::cout << "cluster3" << '\n';
    for (size_t i = 0; i < this->cluster3.size(); i++) {
      /* code */
      for (size_t j = 0; j < this->cluster3[i].size(); j++) {
        /* code */
        std::cout << this->cluster3[i][j] << ' ';
      }
      std::cout << '\n';
    }

    std::cout << "distance1" << '\n';
    for (size_t i = 0; i < this->distance1.size(); i++) {
      /* code */
      std::cout << this->distance1[i] << '\n';
    }

    std::cout << "distance2" << '\n';
    for (size_t i = 0; i < this->distance2.size(); i++) {
      /* code */
      std::cout << this->distance2[i] << '\n';
    }

    std::cout << "distance3" << '\n';
    for (size_t i = 0; i < this->distance3.size(); i++) {
      /* code */
      std::cout << this->distance3[i] << '\n';
    }

    std::cout << "centroid1" << '\n';
    std::cout << this->centroid1[0] << ' ' << this->centroid1[1] << '\n';

    std::cout << "centroid2" << '\n';
    std::cout << this->centroid2[0] << ' ' << this->centroid2[1] << '\n';

    std::cout << "centroid3" << '\n';
    std::cout << this->centroid3[0] << ' ' << this->centroid3[1] << '\n';

  }

  double graph::calculate_distance(
    std::vector<int> p1,
    std::vector<double> p2
  ){
    return sqrt(pow(p1[0]-p2[0], 2.0)+pow(p1[0]-p2[1], 2.0));
  }

  void graph::load_distances(){
    for (size_t i = 0; i < this->points.size(); i++) {
      /* code */
      this->distance1[i]=calculate_distance(this->points[i], this->centroid1);
      this->distance2[i]=calculate_distance(this->points[i], this->centroid2);
      this->distance3[i]=calculate_distance(this->points[i], this->centroid3);
    }
  }

  std::vector<std::vector<double>> graph::minimum_distance(){
    std::vector<std::vector<double>> v;
    double index = 0;
    double minimum_distance = std::numeric_limits<double>::max();
    for (size_t i = 0; i < this->distance1.size(); i++) {
      /* code */
      minimum_distance = std::min(minimum_distance, this->distance1[i]);
      minimum_distance = std::min(minimum_distance, this->distance2[i]);
      minimum_distance = std::min(minimum_distance, this->distance3[i]);

      if (this->distance1[i]==minimum_distance) {
        /* code */
        index = 1;
      }

      if (this->distance2[i]==minimum_distance) {
        /* code */
        index = 2;
      }

      if (this->distance3[i]==minimum_distance) {
        /* code */
        index = 3;
      }
      std::vector<double> x;
      x={minimum_distance, index};
      v.push_back(x);
      minimum_distance = std::numeric_limits<double>::max();
    }

    std::cout << "clustered distances" << '\n';
    for (size_t i = 0; i < v.size(); i++) {
      /* code */
      for (size_t j = 0; j < v[i].size(); j++) {
        /* code */
        std::cout << v[i][j] << '\n';
      }
    }
    return v;
  }
