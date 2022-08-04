def sort
  length = self.length

  (0...length).each do |i|
    (0...(length-i-1)).each do |j|
      self[j], self[j+1] = self[j+1], self[j] if (self[j] > self[j+1])
    end
  end

  self
end

puts "Sorted Array is : #{[92, 54, 65, 85, 29, 23].sort}"
