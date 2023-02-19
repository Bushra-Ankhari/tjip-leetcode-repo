/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution
{
    ///Time Complexity O(10)
    ///Space Complexity O(N)
public:
    random_device rd;
    int offline_guess(string &w1, string &w2)
    {
        int score = 0;
        for(int i = 0; i < w1.size(); i++)
        {
            score += w1[i] == w2[i];
        }
        return score;
    }

    vector<string>prune_based_on_score(int score, vector<string>& words, string &w1)
    {
        vector<string> nwords;
        for(auto &word : words)
        {
            int qscore = offline_guess(w1, word);
            if (qscore == score)
            {
                nwords.push_back(word);
            }
        }
        return nwords;
    }

    void findSecretWord(vector<string>& words, Master& master)
    {
        while(words.size()>1)
        {
            int rdx = rd() % words.size();
            int score = master.guess(words[rdx]);
            words =  prune_based_on_score(score, words, words[rdx]);
        }
        master.guess(words[0]);
    }
};
