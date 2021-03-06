#ifndef SSF_COMMON_CONFIG_PROXY_H_
#define SSF_COMMON_CONFIG_PROXY_H_

#include <string>

#include <boost/property_tree/ptree.hpp>

namespace ssf {
namespace config {

struct Proxy {
 public:
  using PTree = boost::property_tree::ptree;

 public:
  Proxy();

 public:
  void Update(const PTree& pt);

  void Log() const;

  inline bool IsSet() const { return !host_.empty() && !port_.empty(); }

  inline std::string host() const { return host_; }

  inline std::string port() const { return port_; }

  inline std::string username() const { return username_; }

  inline std::string domain() const { return domain_; }

  inline std::string password() const { return password_; }

  inline bool reuse_ntlm() const { return reuse_ntlm_; }

  inline bool reuse_kerb() const { return reuse_kerb_; }

 private:
  // Proxy host
  std::string host_;
  // Proxy port
  std::string port_;
  // Credentials username
  std::string username_;
  // Credentials user's domain
  std::string domain_;
  // Credentials password
  std::string password_;
  // Reuse default NTLM credentials
  bool reuse_ntlm_;
  // Reuse default Kerberos/Negotiate credentials
  bool reuse_kerb_;
};

}  // config
}  // ssf

#endif  // SSF_COMMON_CONFIG_PROXY_H_