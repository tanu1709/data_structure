def sort
  length = self.length

  (0...length).each do |i|
    (i...length).each do |j|
      self[i], self[j] = self[j], self[i] if self[i] > self[j]
    end
  end
  self
end

puts "Sorted Array is : #{[92, 54, 65, 85, 29, 23].sort}"
