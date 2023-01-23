Node *merge(Node *left, Node *right)
{
	Node *dummy = new Node(-1);
	Node *itr = dummy;
	while (left != NULL && right != NULL)
	{
		if (left->data < right->data)
		{
			itr->bottom = left;
			left = left->bottom;
		}
		else
		{
			itr->bottom = right;
			right = right->bottom;
		}
		itr = itr->bottom;
	}
	if (left != NULL)
	{
		itr->bottom = left;
	}
	else
	{
		itr->bottom = right;
	}
	return dummy->bottom;
}
Node *flatten(Node *root)
{
	// Your code here
	if (root == NULL && root->next == NULL)
	{
		return root;
	}
	if (root->next->next == NULL)
		return merge(root, root->next);
	Node *slow = root, *fast = root;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *midnext = slow->next;
	slow->next = NULL;
	Node *left = flatten(root);
	Node *right = flatten(midnext);
	return merge(left, right);
}
