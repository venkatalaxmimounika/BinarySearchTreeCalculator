class Node
  attr_accessor :left, :right, :data

  def initialize(data)
    self.left, self.right, self.data = nil, nil, data
    self
  end

  # def to_s
  #   puts "The value in the node is #{self.data}"
  # end

end