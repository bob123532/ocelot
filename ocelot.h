#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <set>
#include <boost/thread/thread.hpp>

typedef struct {
	int userid;
	std::string peer_id;
	std::string user_agent;
	std::string ip_port;
	std::string ip;
	unsigned int port;
	long long uploaded;
	long long downloaded;
	uint64_t left;
	time_t last_announced;
	time_t first_announced;
	unsigned int announces;
} peer;

typedef std::map<std::string, peer> peer_list;

enum freetype { NORMAL, FREE, NEUTRAL };
enum tokentype { LEECH, SEED };

typedef struct {
	int id;
	time_t last_seeded;
	long long balance;
	int completed;
	freetype free_torrent;
        bool double_seed;
	std::map<std::string, peer> seeders;
	std::map<std::string, peer> leechers;
	std::string last_selected_seeder;
	std::map<int, tokentype> tokened_users;
	time_t last_flushed;
} torrent;

typedef struct {
	int id;
	bool can_leech;
        time_t pfl;     // personal freeleech
} user;


typedef std::unordered_map<std::string, torrent> torrent_list;
typedef std::unordered_map<std::string, user> user_list;
