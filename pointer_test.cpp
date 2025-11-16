#include "iostream"
#include "string"
#include "memory"

class CollectTrigger
{
public:
  virtual void Collect() = 0;
};

class CollectTriggerImplementation final : public CollectTrigger
{
  std::string id;

public:
  CollectTriggerImplementation(const std::string &id)
  {
    this->id = id;
    std::cout << id << " initialized" << std::endl
              << std::flush;
  }

  void Collect()
  {
    std::cout << "collecting metrics" << std::endl
              << std::flush;
    ;
  }

  ~CollectTriggerImplementation()
  {
    std::cout << id << " freed" << std::endl
              << std::flush;
  }
};

std::unique_ptr<CollectTrigger> uniquePtrFactory()
{
  return std::make_unique<CollectTriggerImplementation>("unique ptr");
}

std::shared_ptr<CollectTrigger> sharedPtrFactory()
{
  return std::make_shared<CollectTriggerImplementation>("shared ptr");
}

int main(int argc, char *argv[])
{
  std::unique_ptr<CollectTrigger> uniqueTrigger = uniquePtrFactory();
  std::shared_ptr<CollectTrigger> sharedTrigger = sharedPtrFactory();
  return 0;
}