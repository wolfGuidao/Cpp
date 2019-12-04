class Solution {
public:
	bool Sequence(vector<int> sequence, int start, int end)
	{
		if (sequence.size() < 1 || start > end)
		{
			return false;
		}

		int mid;
		int i;
		int j;
		for (int i = 0; i < end; i++)
		{
			if (sequence[i] > sequence[end])
			{
				mid = i;
				break;
			}
		}
		for (int j = mid; j < end; j++)
		{
			if (sequence[j] < sequence[end])
			{
				return false;
			}
		}
		bool left = true;
		if (i > 0)
		{
			left = Sequence(sequence, 0, mid - 1);
		}
		bool right = true;
		if (j < end)
		{
			right = Sequence(sequence, mid, end);
		}
		return right && left;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() < 1)
		{
			return false;
		}
		if (sequence.size() == 1)
		{
			return true;
		}

		return Sequence(sequence, 0, sequence.size() - 1);

	}
};
class Solution {
public:
	bool Sequence(vector<int> sequence, int start, int end)
	{
		if (sequence.size() < 1 || start > end)
		{
			return false;
		}

		int mid;
		int i;
		int j;
		for (int i = 0; i < end; i++)//遍历数组，因为后序遍历数组中，最后一个元素肯定是根结点
			//又因为是二叉搜索树，所以左子树比根小，右子树比根大，遍历找到第一个比根大的节点
			//用mid记录下来
		{
			if (sequence[i] > sequence[end])
			{
				mid = i;
				break;
			}
		}
		for (int j = mid; j < end; j++)//从第一个比根节点大的节点开始，如果出现比根结点小的节点
			//就直接返回false，否则就说明本次递归满足条件
		{
			if (sequence[j] < sequence[end])
			{
				return false;
			}
		}
		bool left = true;//递归左边的标志
		if (i > 0)
		{
			left = Sequence(sequence, 0, mid - 1);
		}
		bool right = true;//递归右边的标志
		if (j < end)
		{
			right = Sequence(sequence, mid + 1, end - 1);
		}
		return right && left;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() < 1)
		{
			return false;
		}
		if (sequence.size() == 1)
		{
			return true;
		}

		return Sequence(sequence, 0, sequence.size() - 1);

	}
};