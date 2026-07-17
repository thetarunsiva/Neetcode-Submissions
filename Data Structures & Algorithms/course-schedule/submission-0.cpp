class Solution {
public:
    vector<vector<int>> courses;
    vector<int> process;
    bool dfs(int c) {
        if (process[c] == 2) {
            return true;
        }
        if (courses[c].empty()) {
            process[c] = 2;
            return true;
        }
        if (process[c] == 1) {
            return false;
        }
        process[c] = 1;
        for (int i = 0; i < courses[c].size(); i++) {
            int prereq = courses[c][i];
            if (dfs(prereq) == false) {
                return false;
            }
        }
        process[c] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        courses = vector<vector<int>>(numCourses);
        process = vector<int>(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            courses[course].push_back(prereq);
        }
        for (int i = 0; i < numCourses; i++) {
            bool completed = dfs(i);
            if (completed == false) {
                return false;
            }
        }
        return true;
    }
};
