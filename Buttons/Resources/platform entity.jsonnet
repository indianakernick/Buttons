local common = import "common.jsonnet";

function(params) {
  components: {
    PlatformRendering: {},
    Transform: {},
    PhysicsBody: common.getPosSize(params) + {
      body: "platform body.json"
    }
  }
}
