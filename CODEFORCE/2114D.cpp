#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For LLONG_MAX

struct Point {
    int x, y;
};

struct RectBounds {
    int min_x, max_x, min_y, max_y;
};

// Calculates area of a rectangle defined by min/max coordinates
// Also returns width and height through reference parameters
long long calculate_area_and_dims(int min_x, int max_x, int min_y, int max_y, long long& width, long long& height) {
    if (min_x > max_x || min_y > max_y) { // Should only happen if 0 points, not expected here
        width = 0;
        height = 0;
        return 0; 
    }
    
    width = static_cast<long long>(max_x) - min_x + 1;
    height = static_cast<long long>(max_y) - min_y + 1;
    return width * height;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i].x >> p[i].y;
    }

    if (n == 1) {
        std::cout << 1 << std::endl; 
        return;
    }

    std::vector<RectBounds> prefix_bounds(n);
    std::vector<RectBounds> suffix_bounds(n);

    prefix_bounds[0] = {p[0].x, p[0].x, p[0].y, p[0].y};
    for (int i = 1; i < n; ++i) {
        prefix_bounds[i].min_x = std::min(prefix_bounds[i-1].min_x, p[i].x);
        prefix_bounds[i].max_x = std::max(prefix_bounds[i-1].max_x, p[i].x);
        prefix_bounds[i].min_y = std::min(prefix_bounds[i-1].min_y, p[i].y);
        prefix_bounds[i].max_y = std::max(prefix_bounds[i-1].max_y, p[i].y);
    }

    suffix_bounds[n-1] = {p[n-1].x, p[n-1].x, p[n-1].y, p[n-1].y};
    for (int i = n - 2; i >= 0; --i) {
        suffix_bounds[i].min_x = std::min(suffix_bounds[i+1].min_x, p[i].x);
        suffix_bounds[i].max_x = std::max(suffix_bounds[i+1].max_x, p[i].x);
        suffix_bounds[i].min_y = std::min(suffix_bounds[i+1].min_y, p[i].y);
        suffix_bounds[i].max_y = std::max(suffix_bounds[i+1].max_y, p[i].y);
    }

    long long min_cost = LLONG_MAX;


    long long W_all_points, H_all_points;
    min_cost = calculate_area_and_dims(prefix_bounds[n-1].min_x, prefix_bounds[n-1].max_x, 
                                       prefix_bounds[n-1].min_y, prefix_bounds[n-1].max_y,
                                       W_all_points, H_all_points);


    for (int i = 0; i < n; ++i) {
        int current_min_x_others, current_max_x_others, current_min_y_others, current_max_y_others;
        
        if (i == 0) { 

            current_min_x_others = suffix_bounds[1].min_x;
            current_max_x_others = suffix_bounds[1].max_x;
            current_min_y_others = suffix_bounds[1].min_y;
            current_max_y_others = suffix_bounds[1].max_y;
        } else if (i == n - 1) { 

            current_min_x_others = prefix_bounds[n-2].min_x;
            current_max_x_others = prefix_bounds[n-2].max_x;
            current_min_y_others = prefix_bounds[n-2].min_y;
            current_max_y_others = prefix_bounds[n-2].max_y;
        } else { 

            current_min_x_others = std::min(prefix_bounds[i-1].min_x, suffix_bounds[i+1].min_x);
            current_max_x_others = std::max(prefix_bounds[i-1].max_x, suffix_bounds[i+1].max_x);
            current_min_y_others = std::min(prefix_bounds[i-1].min_y, suffix_bounds[i+1].min_y);
            current_max_y_others = std::max(prefix_bounds[i-1].max_y, suffix_bounds[i+1].max_y);
        }
        
        long long W_others, H_others;
        long long area_of_n_minus_1_bb = calculate_area_and_dims(current_min_x_others, current_max_x_others, 
                                                                  current_min_y_others, current_max_y_others,
                                                                  W_others, H_others);
        
        long long cost_this_scenario;
        
        if (area_of_n_minus_1_bb > (static_cast<long long>(n) - 1)) {

            cost_this_scenario = area_of_n_minus_1_bb;
        } else { 
            
            cost_this_scenario = area_of_n_minus_1_bb + std::min(W_others, H_others);
        }
        min_cost = std::min(min_cost, cost_this_scenario);
    }
    
    std::cout << min_cost << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}