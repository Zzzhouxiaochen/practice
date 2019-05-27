#include<bits/stdc++.h>
using namespace std;
int zjf(char c)
{
	if (c >= 'A'&&c <= 'Z')
	{
		return 0;
	}
	else if (c == '@')
	{
		return 0;
	}
	else if (c == ',' || c == '.' || c == ':' || c == '?')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int biao;
	map<char, int>X;
	X['S'] = 1;
	X['A'] = 1;
	X['B'] = 1;
	X['C'] = 0;
	X['D'] = 0;
	int n;
	cout << "输入文法产生式的个数（<=50）:";
	cin >> n;
	string s[51];
	map<char, set<char> > first;
	cout << "输入各产生式（每行一条,空用'@'表示）:" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << "(" << i + 1 << "):";
		cin >> s[i];
	}
	char t[51];
	int k = 0;
	t[0] = s[0][0];
	for (int i = 1; i<n; i++)
	{
		if (s[i][0] != s[i - 1][0])
		{
			t[++k] = s[i][0];
		}
	}
	//	for(int i=0;i<=k;i++)
	//		cout<<t[i]<<endl;
	int q;
	while (1)
	{
		int flag = 0;
		for (int i = 0; i<n; i++)
		{
			for (int j = 3; j<s[i].size(); j++)
			{
				if (zjf(s[i][j]))
				{
					q = first[s[i][0]].size();
					first[s[i][0]].insert(s[i][j]);
					if (q != first[s[i][0]].size())
						flag = 1;
					break;
				}
				if (s[i][j] == '@')
				{
					q = first[s[i][0]].size();
					first[s[i][0]].insert('*');
					if (q != first[s[i][0]].size())
						flag = 1;
					break;
				}
				if (zjf(s[i][j]) == 0)
				{
					q = first[s[i][0]].size();
					set<char>::iterator its;
					for (its = first[s[i][j]].begin(); its != first[s[i][j]].end(); its++)
					{
						if (*its != '*')
							first[s[i][0]].insert(*its);
					}
					if (q != first[s[i][0]].size())
						flag = 1;
					if (X[s[i][j]] == 1)
					{
						biao = j;
					}
					else
					{
						break;
					}
				}
				if (biao == s[i].size() - 1)
				{
					q = first[s[i][0]].size();
					first[s[i][0]].insert('*');
					if (q != first[s[i][0]].size())
						flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
			break;
	}
	for (int i = 0; i <= k; i++)
	{
		cout << "First(" << t[i] << ")" << " = { ";
		set<char>::iterator it;
		for (it = first[t[i]].begin(); it != first[t[i]].end(); it++)
		{
			cout << *it << " ";
		}
		cout << "}" << endl;
	}
}




#include<bits/stdc++.h>
using namespace std;
int zjf(char c)
{
	if (c >= 'A'&&c <= 'Z')
	{
		return 0;
	}
	else if (c == '@')
	{
		return 0;
	}
	else if (c == ',' || c == '.' || c == ':' || c == '?')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int biaoji;
	map<char, int>X;
	X['S'] = 1;
	X['A'] = 1;
	X['B'] = 1;
	X['C'] = 0;
	X['D'] = 0;
	map<char, set<char> > first;
	first['S'].insert('b');
	first['S'].insert('a');
	first['S'].insert('*');
	first['A'].insert('b');
	first['A'].insert('*');
	first['B'].insert('a');
	first['B'].insert('*');
	first['C'].insert('b');
	first['C'].insert('a');
	first['C'].insert('c');
	first['D'].insert('a');
	first['D'].insert('c');
	int n;
	cout << "输入文法产生式的个数（<=50）:";
	cin >> n;
	string s[51];
	map<char, set<char> > follow;
	cout << "输入各产生式（每行一条,空用'@'表示）:" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << "(" << i + 1 << "):";
		cin >> s[i];
	}
	char t[51];
	int k = 0;
	t[0] = s[0][0];
	for (int i = 1; i<n; i++)
	{
		if (s[i][0] != s[i - 1][0])
		{
			t[++k] = s[i][0];
		}
	}
	//	for(int i=0;i<=k;i++)
	//		cout<<t[i]<<endl;
	follow['S'].insert('#');
	int m, q = 3;
	while (q--)
	{
		int ff = 0;
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j<n; j++)
			{
				int flag = 0;
				for (int k = 3; k<s[j].size(); k++)
				{
					if (t[i] == s[j][k])
					{
						m = k + 1;
						flag = 1;
					}
				}
				if (flag == 1)
				{
					if (m == s[j].size())
					{
						q = follow[t[i]].size();
						follow[t[i]].insert(follow[s[j][0]].begin(), follow[s[j][0]].end());
						if (q != follow[t[i]].size())
							ff = 1;
					}
					for (int k = m; k<s[j].size(); k++)
					{
						if (zjf(s[j][k]))
						{
							q = follow[t[i]].size();
							follow[t[i]].insert(s[j][k]);
							if (q != follow[t[i]].size())
								ff = 1;
						}
						if (!zjf(s[j][k]))
						{
							q = follow[t[i]].size();
							set<char>::iterator it;
							for (it = first[s[j][k]].begin(); it != first[s[j][k]].end(); it++)
							{
								if (*it != '*')
									follow[t[i]].insert(*it);
							}
							if (q != follow[t[i]].size())
								ff = 1;
							if (X[s[j][k]])
							{
								biaoji = k;
							}
						}
						if (biaoji == s[j].size() - 1)
						{
							q = follow[t[i]].size();
							follow[t[i]].insert(follow[s[j][0]].begin(), follow[s[j][0]].end());
							if (q != follow[t[i]].size())
								ff = 1;
						}
					}
				}
			}
		}
		if (ff == 0)
			break;
	}
	for (int i = 0; i <= k; i++)
	{
		cout << "Follow(" << t[i] << ")" << " = {";
		set<char>::iterator it;
		for (it = follow[t[i]].begin(); it != follow[t[i]].end(); it++)
		{
			cout << *it << " ";
		}
		cout << "}" << endl;
	}
}





#include<bits/stdc++.h>
using namespace std;
int main()
{
	typedef pair<char, pair<string, string> >PPP;
	vector<PPP >SELECT; //SELECT集
	SELECT.push_back(make_pair('S', make_pair("a", "a")));
	SELECT.push_back(make_pair('S', make_pair("^", "^")));
	SELECT.push_back(make_pair('S', make_pair("(T)", "(")));
	SELECT.push_back(make_pair('T', make_pair("SN", "a")));
	SELECT.push_back(make_pair('T', make_pair("SN", "^")));
	SELECT.push_back(make_pair('T', make_pair("SN", "(")));
	SELECT.push_back(make_pair('N', make_pair("@", ")")));
	SELECT.push_back(make_pair('N', make_pair(",SN", ",")));
	vector<char >Sentence;//要识别的句子
	cout << "请输入要识别的串: " << endl;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		Sentence.push_back(str[i]);
	}
	Sentence.push_back('#');
	//	for(int i=0;i<Sentence.size();i++)
	//	{
	//		cout<<Sentence[i];
	//	}
	vector<char>::iterator a = Sentence.begin(), ii;
	stack<char>S;
	vector<char>vet;
	S.push('#');
	S.push('S');//分析栈
	vet.push_back('#');//存储分析栈
	vet.push_back('S');
	cout << "分析栈" << "              " << "剩余输入串" << "              " << "推导所用的产生式或匹配" << endl;
	int EMPTY = 7;
	string ac[51];
	int k = 0;
	while (!S.empty())
	{
		for (int i = 0; i < vet.size(); i++)   //分析栈
		{
			cout << vet[i] << " ";
		}
		for (int i = vet.size(); i <= EMPTY + 2; i++)
			cout << "  ";
		int count = 0;
		for (ii = a; ii != Sentence.end(); ii++)   //剩余输入串
		{
			cout << (*ii) << " ";
			count++;
		}
		for (; count <= EMPTY; count++)
			cout << "  ";
		char X = S.top();//栈顶符号  *a当前输入符号
		if (X == (*a))
		{
			S.pop();
			vet.pop_back();
			a++;
			for (int i = 0; i <= EMPTY; i++)cout << "  ";
			if (X == '#')
				cout << "接受" << endl;
			else
				cout << "匹配" << endl;
		}
		else
		{
			vector<PPP >::iterator it;
			string ss = "";
			bool flag = false;
			for (it = SELECT.begin(); it != SELECT.end(); it++)
			{
				if (it->first == X)
				{
					ss = it->second.first;//产生式右部 
					for (int i = 0; i < (int)it->second.second.size(); i++)
					{
						if (it->second.second[i] == (*a))
						{
							flag = true;
							break;
						}
					}
					if (flag)break;
				}
			}
			for (int i = 0; i <= EMPTY; i++)cout << "  ";
			if (!flag)
			{
				cout << "ERROR!!!" << endl;
				return 0;
			}
			cout << X << "->" << ss << endl;
			ac[k++] = X + ss;//最左推导存储 
			reverse(ss.begin(), ss.end()); //反转
			if (ss == "@")
			{
				S.pop();
				vet.pop_back();
			}
			else
			{
				S.pop();
				vet.pop_back();
				for (int i = 0; i < (int)ss.size(); i++)
				{
					S.push(ss[i]);
					vet.push_back(ss[i]);
				}
			}
		}
	}
	cout << "最左推导数：" << endl;
	cout << "S=>" << ac[0].substr(1);
	string qq = ac[0].substr(1);
	for (int i = 1; i<k; i++)
	{
		cout << "=>";
		string str1 = "";
		for (int j = 0; j<qq.size(); j++)
		{
			if (ac[i][0] == qq[j])
			{
				if (ac[i].substr(1) == "@")
				{
					str1 += "";
				}
				else
					str1 += ac[i].substr(1);
			}
			else
				str1 += qq[j];
		}
		qq = str1;
		cout << str1;
	}
}


S->a
S->^
S->(T)
T->SN
N->, SN
N->@

