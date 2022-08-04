class Solution {
public:
    vector<string> fullJustify(vector<string> & words, int maxWidth) {
        vector<vector<string> > lines;
        vector<int> sizes;
        for (int i = 0; i < words.size(); i++) { 
            int temp = 0;
            vector<string> singleLine;
            for (int j = i; j < words.size(); j++) { 
                if (temp + words[j].size() <= maxWidth) { 
                    singleLine.push_back(words[j]);
                    temp += 1 + words[j].size();
                }
                else break;
            }
            lines.push_back(singleLine);
            sizes.push_back(temp - singleLine.size());
            i += singleLine.size() - 1;
        }
        vector<string> res;
        for (int i = 0; i < lines.size(); i++) { 
            string temp;
            if (i != lines.size() - 1) { 
                if (lines[i].size() == 1) { 
                    temp += lines[i][0] + string(maxWidth - sizes[i], ' ');
                    res.push_back(temp);
                    continue;
                }
                int spaces = 0, leftover = 0;
                if (lines[i].size() != 1) { 
                    spaces = (maxWidth - sizes[i]) / (lines[i].size() - 1);
                    leftover = (maxWidth - sizes[i]) % (lines[i].size() - 1);
                }
                for (int j = 0; j < lines[i].size(); j++) {
                    if (j == lines[i].size() - 1) { 
                        temp += lines[i][j];
                    }
                    else { 
                        if (leftover > 0) { 
                            leftover--;
                            temp += lines[i][j];
                            temp += string(spaces + 1, ' ');
                        }
                        else { 
                            temp += lines[i][j];
                            temp += string(spaces, ' ');
                        }
                    }
                }
            }
            else {
                int chars = 0;
                for (int j = 0; j < lines[i].size(); j++) { 
                    if (j == lines[i].size() - 1) { 
                        temp += lines[i][j];
                        chars += lines[i][j].size();
                        break;
                    }
                    temp += lines[i][j] + ' ';
                    chars += lines[i][j].size() + 1;
                }
                if (maxWidth - chars > 0)
                    temp += string(maxWidth - chars, ' ');
            }
            res.push_back(temp);
        }
        // for (auto vec : lines) { 
        //     for (auto i : vec) { 
        //         //cout << i << " ";
        //     }
        //     //cout << endl;
        // }
        return res;
    }
};