//
// Created by nikita on 27.06.24.
//

#include "../Traceroute.h"
#include <gtest/gtest.h>

TEST(TracerouteTest, IpFromName) {
    std::string hostname = "localhost";
    std::string expected_ip = "127.0.0.1";
    EXPECT_EQ(Traceroute::ip_from_name(hostname), expected_ip);
}

TEST(TracerouteTest, NameFromIp) {
    std::string ip = "127.0.0.1";
    std::string expected_name = "localhost";
    EXPECT_EQ(Traceroute::name_from_ip(ip), expected_name);
}

TEST(TracerouteTest, InternetChecksum) {
    const char data[] = "test data";
    size_t len = sizeof(data);
    uint16_t checksum = Traceroute::internet_checksum(data, len);
    EXPECT_NE(checksum, 0);
}

TEST(TracerouteTest, Run) {
    Traceroute traceroute;
    std::string ip = "127.0.0.1";
    int max_hops = 30;
    int timeout = 1;
    int start_ttl = 1;
    int retries = 3;

    EXPECT_NO_THROW(traceroute.run(ip, max_hops, timeout, start_ttl, retries));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}