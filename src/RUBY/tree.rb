require_relative 'node.rb'

class Tree
  attr_accessor :root

  def initialize(value)
    self.root = Node.new(value)
    self
  end
  #searching for the value in the tree. Return true if the value is present
  # and false if the value is not present
  def search value
    head = self.root
    while head != nil
      #checking the value of the head is equal to the value we are searching
      # and returns true if the value is present
      if head.data == value
        return true
      end
      #if the value is greater than the value in the head, the head is shifted to right
      if head.data < value
        head = head.right
      #if the value is less than the value in the head, the head is shifted to left
      else
        head = head.left
      end
    end
    false
  end

  #inserting a value into tree if the value is not available
  def insert value
    head = self.root
    #checking if the value is present in tree or not.
    if search(value) == false
      #if the value is not present, inserting at the correct position in the bst
      while head != nil
        #if the value is less than the head value, the head is shifted right and then inserted
        if head.data <= value
          if head.right != nil
            head = head.right
          else
            head.right = Node.new(value)
            head = nil
          end
          #if the value is greater than the head value, the head is shifted left and then inserted
        else
          if head.left != nil
            head = head.left
          else
            head.left = Node.new(value)
            head = nil
          end
        end
      end
    end
  end

  #doing the recursion based inorder traversal along with lambda function
  def inorder l = "->(y){y*1}",head = self.root,out=""
    if head == nil
      return out
    end
    out = self.inorder l,head.left,out
    result = eval("#{l}.call(head.data)").to_s
    # out+= "#{head.data} "
    out += " "+result
    out = self.inorder l,head.right,out
    out
  end

  # invoking inorder
  def to_s
    self.inorder
  end

end