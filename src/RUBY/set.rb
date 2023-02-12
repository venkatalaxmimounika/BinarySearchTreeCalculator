require_relative 'tree.rb'

class Set
  attr_accessor :root

  #creating tree with the given values
  def initialize(array)
    #initializing the root to nil if the given input is empty
    if array.length == 0
      self.root = nil
     #creating tree with the given values
    else
      self.root = Tree.new(array[0])
      for i in 1..array.length-1 do
        root.insert(array[i])
      end
      self
    end
  end

  # doing the union of two sets recursively and storing in x
  def union rooty
    if rooty != nil
      self.union(rooty.left)
      #stroing the value if it is not present in the tree
      if self.root.search(rooty.data) == false
        self.root.insert(rooty.data)
      end
      self.union(rooty.right)
    end
  end

  #doing the intersection of two sets recursively
  def intersection rootx, rooty
    if rooty != nil
      self.intersection(rootx,rooty.left)
      #checking the value in two sets
      if rootx.search(rooty.data) == true
        #checking if the root is nil or not. If the root is null, we are creating a tree
        # and then storing the value in the tree
        if self.root == nil
          self.root =  Tree.new(rooty.data)
        else
          self.root.insert(rooty.data)
        end
      end
      self.intersection(rootx,rooty.right)
    end
  end

  #doing deepcopy. Copying values from x set to y set
  def deepcopy(x)
    self.root = Marshal.load(Marshal.dump(x))
  end

  #switching the values of x and y set
  def switch(y)
    self.root, y.root = y.root, self.root
  end

  #rotating the values of x, y, and z sets
  def rotate(y,z)
    self.root, y.root, z.root = y.root, z.root, self.root
  end

  #inserting the given value at the correct position in the tree
  def ainsert(value)
    self.root.insert(value)
  end

  #returning the tree if it is present otherwise returning an empty string
  def to_s
    if self.root == nil
      return '[]'
    else
      return self.root.inorder
    end
  end
end