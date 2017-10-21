template<typename Comparable>
void AVL_Tree_Node<Comparable>::remove(const Comparable& x, Node_Pointer& t)
{
		if (t == nullptr) 
		{
				throw AVL_Tree_error("blåbärspaj");
		}

		if (x < t->element) 
		{
				remove(x, t->left); // Returnerar hit efter borttagning 
			
		} 
		else if (t->element < x) 
		{
				remove(x, t->right);
		} 
		else 
		{
				// Sökt värde finns i noden t
				Node_Pointer  tmp;

				if (t->left != nullptr && t->right != nullptr) {
						// Noden har två barn och ersätts med inorder efterföljare
						tmp = find_min(t->right);
						t->element = tmp->element;
						remove(t->element, t->right);
				}
				else {
						// Noden har inget eller ett barn
						tmp = t;

						if (t->left == nullptr)
								t = t->right;
						else
								t = t->left;

						delete tmp;
				}
		}

		if(t != nullptr)
		{
				calculate_height(t);  // Uppdaterar höjden i t 
				if (node_height(t->right) - node_height(t->left) == 2)
				{
						if (t->right->right->height >= node_height(t->right->left))
								single_rotate_with_right_child(t);
						else
								double_rotate_with_right_child(t);
				}
				if (node_height(t->left) - node_height(t->right) == 2)
				{
						if (node_height(t->left->left) >= node_height(t->left->right))
								single_rotate_with_left_child(t);
						else
								double_rotate_with_left_child(t);
				}
		}
}
