def sort
  length = self.length

  (0...length).each do |i|
    (0...(i+1)).each do |j|
      break if self[j].nil?
      self[i], self[j] = self[j], self[i] if self[j] > self[i]
    end
  end
  self
end

puts "Sorted Array is : #{[92, 54, 65, 85, 29, 23].sort}"
