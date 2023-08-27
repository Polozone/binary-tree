# binary-tree

As I was interested by putting index on certains columns of a SQL database (to improve 
performance for GET request), I discovered the power of binary tree. Binary tree is
very efficient when it comes to order data and access to it quickly.

To learn more about that subject, I made a little repository where i manipulate binary tree.

I implemented a LIFO for the readTree function. I needed a way to save a 'checkpoint' when I
need to go back to a certain node when I readed an entiere branch. (I was lazy to save a 'parent
pointer', and I prefer the design where I can 'teleport' the execution to an old node where there
is still data to read on the right pointer).

I will update this project for new features :

- Keep a good balance of the tree when I insert data. (the actual value of root node can't change, that
mean that the tree won't be balanced if we had more data at left than right, and inverse). So the
addNode functions need an update.
- Check for memory leaks.
- Secure NULL root.
