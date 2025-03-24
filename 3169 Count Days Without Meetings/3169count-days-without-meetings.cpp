class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());
        int count = 0;
        int curs = -1, cure = -1;

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > cure) {
                if (cure != -1) {
                    count += cure - curs + 1;
                }
                curs = start;
                cure = end;
            } else {
                cure = std::max(cure, end);
            }
        }

        if (cure != -1) {
            count += cure - curs + 1;
        }

        return days - count;
    }
};