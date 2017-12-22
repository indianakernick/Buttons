local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["font size", "pos", "text"]) {
    TextRendering: {
      font: "Arial.ttf",
      size:
        if "font size" in params then
          params["font size"]
        else
          32
      ,
      "hori align": "center",
      "vert align": "middle",
      depth: common.getDepth("text")
    },
    Transform: common.getPos(params),
    Text:
      if "text" in params then
        params.text
      else
        ""
  }
}
