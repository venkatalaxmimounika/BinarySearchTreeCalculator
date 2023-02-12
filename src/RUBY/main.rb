require_relative 'set.rb'
require_relative 'node.rb'

#initializing the trees with empty arrays
xoutput, youtput, zoutput = Set.new([]), Set.new([]), Set.new([])
temp = true
puts 'Enter the name of the set and values to create the tree like "X 2,3,4,-1"'
puts 'X values creates X set'
puts 'Y values creates X set'
puts 'Z values creates X set'
puts 'a i inserts a value into the set'
puts 'r rotes the contents of all the three trees'
puts 's swtiches the X and Y trees'
puts 'u gives the union of X and Y in X'
puts 'i gives the intersection of X and Y in X'
puts 'c recursively deep copies X into Y'
puts 'l aString perfoms lambda function on each value of set X and displays the output'
puts 'q quits the command'
puts 'Enter any commands for the above to perform the operation'
#printing all the values of the set
def printl(xoutput, youtput, zoutput)
  print 'X set :'
  print xoutput
  puts ''
  print 'Y set :'
  print youtput
  puts ''
  print 'Z set :'
  print zoutput
end

#calling the particular function according to the input given by the user
while temp
  input = gets.chomp
  # name = input.split(' ')
  cmd = input[0]
  case cmd

  #X tree is created when X set values are given by the user
  when 'X'
    if input[2..]
      newString = input[2..]
      newString = newString.split(",")
      datainputx = []
      for i in 0..newString.length-1 do
        if newString[i] != "" or newString[i] != " "
          datainputx.append(newString[i].to_i)
        end
      end
      xoutput = Set.new datainputx
      end
    printl(xoutput, youtput, zoutput)

    #Y tree is created when Y set values are given by the user
    when 'Y'
    if input[2..]
      newString = input[2..]
      newString = newString.split(",")
      datainputy = []
      for i in 0..newString.length-1 do
        if newString[i] != "" or newString[i] != " "
          datainputy.append(newString[i].to_i)
        end
      end
      youtput = Set.new datainputy
    end
    printl(xoutput, youtput, zoutput)

  #Z tree is created when Z set values are given by the user
  when 'Z'
    if input[2..]
      newString = input[2..]
      newString = newString.split(",")
      datainputz = []
      for i in 0..newString.length-1 do
        if newString[i] != "" or newString[i] != " "
          datainputz.append(newString[i].to_i)
        end
      end
      zoutput = Set.new datainputz
    end
    printl(xoutput, youtput, zoutput)

   #rotation is called when r is given by the user
  when 'r'
    xoutput.rotate(youtput, zoutput)
    printl(xoutput, youtput, zoutput)

  #inserting at specific position is called when a is given by the user
  when 'a'
    if input[2..]
      newString = input[2..]
      newString = newString.split(",")
      if xoutput.root == nil
        xoutput.root = Tree.new(newString[0].to_i)
      else
        xoutput.ainsert(newString[0].to_i)
      end
    end
    printl(xoutput, youtput, zoutput)

  #switching is called when s is given by the user
  when 's'
    if xoutput.root == nil and youtput.root == nil
      printl(xoutput, youtput, zoutput)
    else
      xoutput.switch(youtput)
      printl(xoutput, youtput, zoutput)
    end


    #union is called when u is given by the user
  when 'u'
    if youtput.root != nil and xoutput.root != nil
      xoutput.union(youtput.root.root)
      printl(xoutput, youtput, zoutput)
    end
    if youtput.root == nil and xoutput.root != nil
      printl(xoutput, youtput, zoutput)
    end
    if xoutput.root == nil and youtput.root != nil
      xoutput.deepcopy(youtput.root)
      printl(xoutput, youtput, zoutput)
    end
    if xoutput.root == nil and youtput.root == nil
      printl(xoutput, youtput, zoutput)
    end

    #intersection is called when i is given by the user
  when 'i'
    if youtput.root == nil or xoutput.root == nil
      xoutput = Set.new([])
      printl(xoutput, youtput, zoutput)
    else
      ioutput = Set.new([])
      ioutput.intersection(xoutput.root, youtput.root.root)
      xoutput = ioutput
      printl(xoutput, youtput, zoutput)
    end

    #deepycopy is called when c is given by the user
  when 'c'
    youtput.deepcopy(xoutput.root)
    printl(xoutput, youtput, zoutput)

  #lambda functio is called when l is given by the user
  when 'l'
    newString = input[2..]
    newString = newString.split(",")
    if xoutput.root == nil
      print 'lambda of set X is empty'
    else
      newString[0]
      print 'lambda values :'
      print xoutput.root.inorder(newString[0])
    end
    puts ''
    printl(xoutput, youtput, zoutput)

    #printing all sets
  when 'p'
    printl(xoutput, youtput, zoutput)

  #quitting the program when q is calle
  when 'q'
    temp = false
  end

end