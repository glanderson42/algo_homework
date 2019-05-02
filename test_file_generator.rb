#!/ usr / bin / ruby

unless ARGV.length == 1
    puts "Wrong useage"
    puts "Usage: ruby test_file_generator.rb <number of testcases>"
    exit
end

num_of_files = ARGV[0].to_i

for f in 1..num_of_files
    random_num = rand(1..1000)

    file = File.new("test_files/graph_#{f}", "w")

    file.write("#{random_num}\n")

    for i in 1..random_num
        random_begin = rand(0..1000)
        random_end = rand(0..1000)
        random_weight = rand(0.01..1.0)
        puts "> #{random_begin} :: #{random_end} :: #{random_weight}"
        file.write("#{random_begin} #{random_end} #{random_weight}\n")
    end
end
